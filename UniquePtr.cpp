#include "UniquePtr.h"
#include <cstring>
#include <algorithm>
#include <iostream>

UniquePtr::UniquePtr() {
	_ptr = nullptr;
}

UniquePtr::UniquePtr(ValueType* ptr) {
	_ptr = ptr;
}

UniquePtr::UniquePtr(UniquePtr&& o) {
	this->_ptr = o._ptr;
	o._ptr = nullptr;
	std::cout << "move construct \n";
}

UniquePtr& UniquePtr::operator=(UniquePtr&& o) {
	std::cout << "move operation \n";
	if (o._ptr == _ptr)
		return *this;
	if (_ptr != nullptr) {
		delete[] _ptr;
	}
	_ptr = nullptr;
	std::swap(_ptr, o._ptr);
	return *this;
}

UniquePtr& UniquePtr::operator=(ValueType* ptr) {
	std::cout << " operator = \n";
	if (this != nullptr) {
		delete[] _ptr;
	}
	_ptr = ptr;
	return *this;
}

void UniquePtr::reset() {
	reset(nullptr);
}

void UniquePtr::reset(ValueType* ptr) {
	std::cout << "this is empty " << static_cast<bool>(this) << std::endl;
	if (this != nullptr) {
		delete[] _ptr;
	}
	_ptr = ptr;
}

void UniquePtr::release() {
	_ptr = nullptr;
}

UniquePtr::operator bool() const {
	return _ptr;
}

ValueType& UniquePtr::operator*() const {
	return *_ptr;
}

ValueType* UniquePtr::operator->() const {
	return get();
}

ValueType* UniquePtr::get() const {
	return _ptr;
}