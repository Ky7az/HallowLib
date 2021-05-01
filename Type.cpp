#include "Type.h"
using namespace std;

Type* init_type_template(TypeEnum type)
{
	Type *type_ret = NULL;

	switch (type)
	{
		case TYPE_BYTE:
			type_ret = new TypeTpl<byte>;
			break;
		case TYPE_SHORT:
			type_ret = new TypeTpl<short>;
			break;
		case TYPE_INTEGER:
			type_ret = new TypeTpl<int>;
			break;
		case TYPE_FLOAT:
			type_ret = new TypeTpl<float>;
			break;
		case TYPE_DOUBLE:
			type_ret = new TypeTpl<double>;
			break;
		case TYPE_STRING:
			type_ret = new TypeTpl<char>;
			break;
		case TYPE_BYTES:
			type_ret = new TypeTpl<unsigned char>;
			break;
	}

	return type_ret;
}

