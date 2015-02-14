#include "IdMgr.h"

using namespace std;

UInt IdMgr::instanceCount = 0;

Id::Id()
{
	_Id = __IdInvalid;
	_IdMgrPtr = NULL;
}

Id::Id(SHARED_PTR<IdMgr> IdMgrPtr)
{
	_IdMgrPtr = IdMgrPtr;
	if (_IdMgrPtr)
		_Id = _IdMgrPtr->_nextId++;
	else
		_Id = __IdInvalid;
}

Id::Id(SHARED_PTR<IdMgr> IdMgrPtr, IdType id)
{
	_IdMgrPtr = IdMgrPtr;
	_Id = id;
}

Id::~Id()
{
	if (_IdMgrPtr && _IdMgrPtr->reuseIds)
		_IdMgrPtr->ReclaimId(Get());
}

IdType Id::Get()
{
	return _Id;
}

IdMgr::IdMgr()
{
	_currentMaxIdAllotted = __IdStart;
	_freeIdList = vector<Id>();
}

IdMgr::~IdMgr()
{

}

SHARED_PTR<IdMgr> IdMgr::GetNewInstance(bool reuseIds)
{
	SHARED_PTR<IdMgr> sIdMgrPtr = make_shared<IdMgr>(new IdMgr(reuseIds));
	instanceCount++;
	return sIdMgrPtr;
}

Id IdMgr::GetNextId()
{
	if (!_freeIdList.empty())
	{
		Id IdFromFreeList = _freeIdList.front();
		_freeIdList.pop_front();		
		return IdFromFreeList;
	}

	return make_shared<Id>(Id(shared_from_this()));
}

void IdMgr::ReclaimId(IdType freeId)
{
	_freeIdList.push_back(freeId);
}