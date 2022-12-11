#ifndef OMP_NESTED_SCOPED_LOCK_
#define OMP_NESTED_SCOPED_LOCK_
 
#include <omp.h>

class OMP_NestedScopeLock {
public:
      // Acquire the lock and store a pointer to it
    OMP_NestedScopeLock (omp_nest_lock_t &lock);
      // Set the lock explicitly
    void acquire ();
      // Release the lock explicity
    void release ();
      // Destructor for mested scoped lock object
    ~OMP_NestedScopeLock ();

private:
    omp_nest_lock_t *_mylock;  // pointer to my lock

    // Disallow copies or assignment
    OMP_NestedScopeLock (const OMP_NestedScopeLock &);
    void operator= (const OMP_NestedScopeLock &);
};

#endif

// Construct OMP_NestedScopeLock object and acquire my lock
OMP_NestedScopeLock::OMP_NestedScopeLock (omp_nest_lock_t &lock) : _mylock (&lock)
{
    acquire ();
}

// Explicitly set my lock
void OMP_NestedScopeLock::acquire ()
{
        omp_set_nest_lock (_mylock);
}

// Explicitly unset my lock.
void OMP_NestedScopeLock::release ()
{
        omp_unset_nest_lock (_mylock);
}

// Destruct OMP_NetsedScopeLock object, release the lock
OMP_NestedScopeLock::~OMP_NestedScopeLock ()
{
    release ();
}

