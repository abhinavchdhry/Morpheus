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
	if (_IdMgrPtr.lock())
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
	shared_ptr<IdMgr> sIdMgrPtr(new IdMgr(reuseIds));
	instanceCount++;
	return sIdMgrPtr;
}

IdPtr IdMgr::GetNextId()
{
	if (_reuseIds && !_freeIdList.empty())
	{
		IdType IdFromFreeList = _freeIdList.front();
		_freeIdList.pop_front();
		/* XXX: Never create a locally-scoped stack object of Id here (shared_ptr from 'new' only),
		 * as the destructor called at the end of this scope would reclaim the Id and wreak havoc */
		return IdPtr(new Id(shared_from_this(), IdFromFreeList));
	}

	return IdPtr(new Id(shared_from_this()));
}

void IdMgr::ReclaimId(IdType freeId)
{
	if (_reuseIds)
		_freeIdList.push_back(freeId);
}
