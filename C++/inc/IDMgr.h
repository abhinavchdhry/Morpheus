#include "CommonIncludes.h"

using namespace std;

/* In case ID Type needs to be changed, it can be changed here */
typedef uint32_t IdType;

enum {
	__IdInvalid = 0,
	__IdStart = 1,
};

class IdMgr;

class Id {
public:
	Id::Id();
	Id(shared_ptr<IdMgr> IdMgrPtr);
	Id::Id(shared_ptr<IdMgr> IdMgrPtr, IdType id);
	~Id();

	virtual IdType Get();

private:
	IdType 			_Id;
	weak_ptr<IdMgr> _IdMgrPtr;
};

class IdMgr : public enable_shared_from_this<IdMgr> {
	friend class Id;
public:
	static uint32_t instanceCount;
	static shared_ptr<IdMgr> GetNewInstance(bool reuseIds=false);

	virtual Id GetNextId();
	virtual void ReclaimId(IdType id);

	IdMgr(bool reuseIds=false);
	~IdMgr();

private:
	bool		 _reuseIds;
	IdType 		 _nextId;
	list<IdType> _freeIdList;
};