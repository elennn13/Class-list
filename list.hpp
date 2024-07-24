#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <iostream>
#include <initializer_list>

template <typename ANY >
class List {

private:
	struct Item {
		ANY value = ANY(); // значение //ANY() вызываем конструктор по умолчанию
		Item* next = nullptr; //следующий
		Item* prev = nullptr; //предыдущий
		Item(ANY value) : value(value) {}
	};
	Item* first;
	Item* last;
	size_t length; // поле для хранения размера списка
	void set_defaults();
public:
	List(); //определение конструктор 
	List(const std::initializer_list<ANY>&ints);


	~List(); //определение деструктора

	void print() const;
	void reverse_print() const;

	void push_back(ANY value);
	void push_front(ANY value);
	void pop_back();
	void pop_front();
	void clear();

	size_t size() const;
	ANY& front();
	const ANY& front() const;
	ANY& back();
	const ANY& back() const;
};

template<typename ANY>
void List<ANY>::set_defaults() {
	first = nullptr;
	last = nullptr;
	length = 0;

}

template<typename ANY>
List<ANY>::List() : first(nullptr), last(nullptr), length(0){}

template<typename ANY>
List<ANY>::List(const std::initializer_list<ANY>& inits)
{
	set_defaults();
	for (auto el : inits)
		push_back(el);
}

template<typename ANY>
List<ANY>::~List() { clear(); }

template<typename ANY>
void List<ANY>::print() const {
	if (first == nullptr) {
		std::cout << '\n';
		return;
	}
	Item* current = first; //указатель на текущий элемент
	do {
		std::cout << current->value << ' ';
		current = current->next;
	} while (current != nullptr);
	std::cout << std::endl;
}

template<typename ANY>
void List<ANY>::reverse_print() const {
	if (last == nullptr) {
		std::cout << '\n';
		return;
	}
	Item* current = last; //указатель на текущий элемент
	do {
		std::cout << current->value << ' ';
		current = current->prev;
	} while (current != nullptr);
	std::cout << std::endl;

}

template<typename ANY>
void List<ANY>::push_back(ANY value){
	if (last == nullptr) {
		last = first = new Item(value);
		++length;
		return;
	}

	last->next = new Item(value);
	last->next->prev = last;
	last = last->next;
	++length;


}

template<typename ANY>
inline void List<ANY>::push_front(ANY value) {
	if (first == nullptr) {
		first = last = new Item(value);
		++length;
		return;
	}

	first->prev = new Item(value);
	first->prev->next = first;
	first = first->prev;
	++length;
}

template<typename ANY>
void List<ANY>::pop_back() {
	if (last == nullptr)
		throw std::exception("List have no elements");

	if (first == last) { // когда один элемент
		delete last;
		set_defaults();
		return;
	}

	last = last->prev;  //если несколько элементов удаляем последний.
	delete last->next;
	last->next = nullptr;
	--length;
}

template<typename ANY>
void List<ANY>::pop_front() {
	if (first == nullptr)
		throw std::exception("List have no elements");

	if (first == last) { // когда один элемент
		delete first;
		set_defaults();
		return;
	}

	first = first->next;  //если несколько элементов удаляем последний.
	delete first->prev;
	first->prev = nullptr;
	--length;
}

template<typename ANY>
void List<ANY>::clear() {
	if (first == nullptr)
		return;

	Item* current = first;
	do {
		Item* to_delete = current;
		current = current->next;
		delete to_delete;
	} while (current != nullptr);

	set_defaults();
	}

template<typename ANY>
size_t List<ANY>::size() const
{
	return length;
}

template<typename ANY>
inline ANY& List<ANY>::front() { 
	return first->value;
}

template<typename ANY>
inline const ANY& List<ANY>::front() const
{
	return first->value;
}

template<typename ANY>
inline ANY& List<ANY>::back()
{
	return last->value;
}

template<typename ANY>
inline const ANY& List<ANY>::back() const
{
	return first->value;
}




#endif // _LIST_HPP_