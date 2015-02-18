#include "IDMgr.h"

using namespace std;

uint32_t IdMgr::instanceCount = 0;

Id::Id()
{
	_Id = __IdInvalid;
	_IdMgrPtr.reset();
}

Id::Id(shared_ptr<IdMgr> IdMgrPtr)
{
	_IdMgrPtr = IdMgrPtr;
	if (_IdMgrPtr.lock())
		_Id = _IdMgrPtr.lock()->_nextId++;
	else
		_Id = __IdInvalid;
}

Id::Id(shared_ptr<IdMgr> IdMgrPtr, IdType id)
{
	_IdMgrPtr = IdMgrPtr;
	_Id = id;
}

Id::~Id()
{
	if (_IdMgrPtr.lock() && _IdMgrPtr.lock()->_reuseIds)
		_IdMgrPtr.lock()->ReclaimId(Get());
}

IdType Id::Get()
{
	return _Id;
}

IdMgr::IdMgr(bool reuseIds)
{
	_reuseIds = reuseIds;
	_nextId = __IdStart;
	_freeIdList = list<IdType>();
}

IdMgr::~IdMgr()
{

}

shared_ptr<IdMgr> IdMgr::GetNewInstance(bool reuseIds)
{
	shared_ptr<IdMgr> sIdMgrPtr = make_shared<IdMgr>(new IdMgr(reuseIds));
	instanceCount++;
	return sIdMgrPtr;
}

Id IdMgr::GetNextId()
{
	if (!_freeIdList.empty())
	{
		IdType IdFromFreeList = _freeIdList.front();
		_freeIdList.pop_front();		
		return Id(shared_from_this(), IdFromFreeList);
	}

	return Id(shared_from_this());
}

void IdMgr::ReclaimId(IdType freeId)
{
	_freeIdList.push_back(freeId);
}
