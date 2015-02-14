#include "Types.h"
#include <memory>

using namespace std;

/* In case ID Type needs to be changed, it can be changed here */
typedef UInt IdType;

enum {
	__IdInvalid = 0,
	__IdStart = 1,
}

class IdMgr;

class Id {
public:
	Id(IdType);
	Id(SHARED_PTR<IdMgr> IdMgrPtr);
	~Id();

	virtual IdType Get();

private:
	IdType 			_Id;
	WEAK_PTR<IdMgr> _IdMgrPtr;
};

class IdMgr : enable_shared_from_this<IdMgr> {
	friend class Id;
public:
	static UInt instanceCount;
	static SHARED_PTR<IdMgr> GetNewInstance(bool reuseIds=false);

	virtual Id GetNextId();
	virtual void ReclaimId(IdType id);

protected:
	IdMgr(bool reuseIds=false);
	~IdMgr();

private:
	bool		 _reuseIds;
	IdType 		 _nextId;
	list<IdType> _freeIdList;
};