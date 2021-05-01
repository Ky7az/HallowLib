#ifndef __TYPE_H__
#define __TYPE_H__

/** INCLUDES **/
#include <cstddef>
#include <iostream>
#include <windows.h>

/** DEFINES **/
enum TypeEnum
{
	TYPE_BYTE,
	TYPE_SHORT,
	TYPE_INTEGER,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_STRING,
	TYPE_BYTES
};

/** CLASSES **/
/* Type */
class Type
{
public:
	virtual ~Type() {};

	virtual void* allocate() const = 0;
	virtual void* cast(void *obj) const = 0;

	virtual void copy(void *dst, void *src) const = 0;

	virtual bool is_equal(void *obj1, void *obj2) const = 0;
	virtual bool is_different(void *obj1, void *obj2) const = 0;
	virtual bool is_lower(void *obj1, void *obj2) const = 0;
	virtual bool is_greater(void *obj1, void *obj2) const = 0;

	virtual void print(void *obj) const = 0;
};

template<typename T>
class TypeTpl : public Type
{
public:
	virtual void* allocate() const { return new T; }
	virtual void* cast(void *obj) const { return static_cast<T*>(obj); }

	virtual void copy(void *dst, void *src) const { *static_cast<T*>(dst) = *static_cast<T*>(src); }

	virtual bool is_equal(void *obj1, void *obj2) const { return *static_cast<T*>(obj1) == *static_cast<T*>(obj2); }
	virtual bool is_different(void *obj1, void *obj2) const { return *static_cast<T*>(obj1) != *static_cast<T*>(obj2); }
	virtual bool is_lower(void *obj1, void *obj2) const { return *static_cast<T*>(obj1) < *static_cast<T*>(obj2); }
	virtual bool is_greater(void *obj1, void *obj2) const { return *static_cast<T*>(obj1) > *static_cast<T*>(obj2); }

	virtual void print(void *obj) const { cout << *static_cast<T*>(obj); }
};

/** FUNCTIONS **/
Type* init_type_template(TypeEnum type);

#endif