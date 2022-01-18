#include <iostream>
using namespace std;
template<class T>
class UniquePtr
{
public:
	T* ptr;
	UniquePtr() {
		T* ptr = nullptr;
	}
	UniquePtr(T* m_ptr) {
		ptr = m_ptr;
	}
	~UniquePtr() {
		delete ptr;
	}
	UniquePtr(UniquePtr& a) {
		ptr = a.ptr;
		a.ptr = nullptr;
	}
	UniquePtr& operator=(UniquePtr& a) {
		if (&a == this) {
			return *this;
		}
		delete ptr;
		ptr = a.ptr;
		a.ptr = nullptr;
		return *this;
	}
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	void isNull() const { if (ptr == nullptr)cout << "null"; else cout << "not null"; }
};
template<class T>
class SharePtr
{
public:
	T* ptr = nullptr;
	size_t* count = nullptr;

	SharePtr(T* m_ptr) :ptr(m_ptr), count(new size_t(1)) {}
	SharePtr(const SharePtr& m_ptr) :
		ptr(m_ptr.ptr), count(m_ptr.count)
	{
		++* count;
	}
	SharePtr(SharePtr&& m_ptr) :
		ptr(m_ptr.ptr), count(m_ptr.count)
	{
		m_ptr.ptr = nullptr;
		m_ptr.count = nullptr;
	}
	~SharePtr()
	{
		if (*count > 1)
		{
			--* count;
			return;
		}
		delete ptr;
		delete count;
	}
	T& operator*() const { return *ptr; }
	T& operator->() const { return ptr; }
	void isNull() const { if (ptr == nullptr)cout << "null"; else cout << "not null"; cout << " " << *count << " copy. Value = " << *ptr; }
};

class Item
{
public:
	Item() {}
	~Item() {}
};

int main()
{
	setlocale(LC_ALL, "");
	cout << "\nUnique ptr:";
	UniquePtr<Item> item1(new Item);
	UniquePtr<Item> item2;

	cout << "\nitem1 is "; item1.isNull();
	cout << "\nitem2 is "; item2.isNull();
	item2 = item1;
	cout << "\nOwnership transferred\n";
	cout << "\nitem1 is "; item1.isNull();
	cout << "\nitem2 is "; item2.isNull();

	cout << "\n\nShare ptr:";
	SharePtr<int> item3(new int(10));
	cout << "\nitem3 is "; item3.isNull();
	SharePtr<int> item4(item3);
	cout << "\nitem4 is "; item4.isNull();
	SharePtr<int> item5(item3);
	cout << "\nitem5 is "; item5.isNull();
	cout << "\nDelete item 3:";
	item3.~SharePtr();
	cout << "\nitem3 is "; item3.isNull();
	cout << "\nitem4 is "; item4.isNull();
	cout << "\nitem5 is "; item5.isNull();
	return 0;
}