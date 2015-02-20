#ifndef _IdMgr_h_
#define _IDMgr_h_

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
	friend class IdMgr;
	/* All constructors for Id are private to prevent
	 * Ids being created without an IdMgr
	 */
	Id();
	Id(shared_ptr<IdMgr> IdMgrPtr);
	Id(shared_ptr<IdMgr> IdMgrPtr, IdType id);

public:
	~Id();
	virtual IdType Get();

private:
	IdType 			_Id;
	weak_ptr<IdMgr> _IdMgrPtr;
};

typedef shared_ptr<Id> IdPtr;

class IdMgr : public enable_shared_from_this<IdMgr> {
	friend class Id;

public:
	static shared_ptr<IdMgr> GetNewInstance(bool reuseIds=false);
	virtual IdPtr GetNextId();
	~IdMgr();

private:
	IdMgr(bool reuseIds=false);
	virtual void ReclaimId(IdType id);

private:
	/* No. of instances of IDMgr created */
	static uint32_t instanceCount;

	bool		 _reuseIds;
	IdType 		 _nextId;
	list<IdType> _freeIdList;
};

#endif /* _IdMgr_h_ */
