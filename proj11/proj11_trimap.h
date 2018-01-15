#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
using std::string;

// forward declaration so we can make Element a friend of TriMap
template<typename K, typename V>
class TriMap;

// private Element, friend of TriMap class
template <typename K, typename V>
class Element{

private:
  K key_;
  size_t index_ = 0;
  Element *next_ = nullptr;  

public:
  V value_;
  
  Element() = default;
  Element(K key, V val, size_t i) : key_(key),index_(i), next_(nullptr), value_(val) {};

  // *defined* in the class, makes templating easier.
  friend ostream& operator<<(ostream& out, Element& e){
    out << e.key_ << ":" << e.value_ << ":" << e.index_;
    return out;
  }
  friend class TriMap<K,V>;
};


template<typename K, typename V>
class TriMap{

private:
  Element<K,V> *head_ = nullptr;
  Element<K,V> *tail_ = nullptr;
  size_t size_ = 0;
  
  // a private function, used by operator<<
  void print_list(ostream& out);
  
public:
  TriMap() = default;
  TriMap(K, V);
  TriMap(const TriMap&);
  TriMap& operator=(TriMap);
  ~TriMap();
  long size();
  bool insert(K,V);
  bool remove(K);
  Element<K,V>* find_key(K);
  Element<K,V>* find_value(V);
  Element<K,V>* find_index(size_t);  
  
  // *defined* in the class, makes templating easier.
  // uses private method print_list
  // you can remove print_list and just do it here if you
  // prefer. I won't test print_list
  friend ostream& operator<<(ostream& out, TriMap<K,V>& sl){
    sl.print_list(out);
    return out;
  };
};

template<typename K, typename V>
TriMap<K,V>::TriMap(K key, V value){
	insert(key, value);
};

/* 
bit of work. we need to remember a pointer that walks
down the list to copy, as tail_ walks down the new list. 
Make a new node (copy the current node of the list we are copying), 
update the tail_->next_ to point to the new node, update tail_ to new node
 */
template<typename K, typename V>
TriMap<K,V>::TriMap(const TriMap& tm){
	/*head_ = nullptr;
	tail_ = nullptr;

	auto tmp = tm.head_;
	while (tmp)
	{
		insert(tmp->key_, tmp->value_);
		tmp = tmp->next_;
	}*/
	
if (tm.head_ == nullptr){
	head_ = nullptr;
	tail_ = nullptr;
    }
    else{
    head_ = new Element<K,V>(tm.head_->key_,tm.head_->value_,tm.head_->index_);
	tail_ = head_;
	Element<K,V>* tm_ptr = tm.head_->next_;
	Element<K,V>* new_element;
	while (tm_ptr != nullptr){
	    new_element = new Element<K,V>(tm_ptr->key_,tm_ptr->value_,
	    tm_ptr->index_);
	    tail_->next_ = new_element;
	    tm_ptr = tm_ptr->next_;
	    tail_ = new_element;
	    size_ = tm.size_;
	    }
	    
    }
}


template<typename K, typename V>
TriMap<K,V>& TriMap<K,V>::operator=(TriMap tm){
	swap(head_,tm.head_);
	swap(tail_,tm.tail_);
	swap(size_,tm.size_);
	return *this;
}
	

// walk down the list using head_ , keeping a trailer pointer called to_del
// delete what to_del points to
// move head_ and to_del to the next node.
template<typename K, typename V>
TriMap<K,V>::~TriMap(){
	while (head_)
	{
		auto to_del = head_;
		head_ = head_->next_;
		delete to_del;
	}
}

template<typename K, typename V>
long TriMap<K,V>::size(){
	return size_;
}

template<typename K, typename V>
bool TriMap<K,V>::insert(K key, V value){
  // very important, what are all the cases here!!!!
  // elements are inserted in *key order*
	if (!head_)
	{
		head_ = new Element<K, V>(key, value, 0);
		tail_ = head_;
		size_++;
		return true;
	}
	else
	{
		auto tmp = head_;
		Element<K, V> *prev = nullptr;

		// Find the place where we should insert our node
		while (tmp && tmp->key_ < key)
		{
			prev = tmp;
			tmp = tmp->next_;
		}

		// Check if element with same key is already present
		if (tmp && tmp->key_ == key)
			return false;

		auto new_el = new Element<K, V>(key, value, size());
		size_++;

		if (prev)
		{
			prev->next_ = new_el;
			new_el->next_ = tmp;
		}
		else
		{
			// Adding to the beginning of the list
			new_el->next_ = tmp;
			head_ = new_el;
		}

		// Update tail if tmp is null since we're adding to the end of the list.
		if (!tmp)
		{
			tail_ = new_el;
		}

		return true;
	}

	return false;
}
    
template<typename K, typename V>
bool TriMap<K,V>::remove(K key){
  // If you delete a node, the indicies of all
  // nodes with a higher index have that index reduced by one

	if (!head_)
		return false;

	// Find node to delete
	auto tmp = head_;
	auto prev = tmp;
	while (tmp && tmp->key_ != key)
	{
		prev = tmp;
		tmp = tmp->next_;
	}

	// Node not found?
	if (!tmp)
	{
		return false;
	}

	if (head_ == tmp)
	{
		head_ = head_->next_;
	}

	if (tail_ == tmp)
	{
		tail_ = prev;
	}

	if (prev)
	{
		prev->next_ = tmp->next_;
	}

	unsigned int index = tmp->index_;
	delete tmp;
	
	// Update elements with a higher index need to be updated
	auto el_to_update = head_;
	while (el_to_update)
	{
		if(el_to_update->index_ > index)
			el_to_update->index_--;

		el_to_update = el_to_update->next_;
	}

	size_--;

	return true;
}
 

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_key(K key){
  // no binary search, just linear search
	auto tmp = head_;
	while (tmp && tmp->key_ != key)
	{
		tmp = tmp->next_;
	}

	return tmp;
}    

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_value(V val){
  // linear search
	auto tmp = head_;
	while (tmp && tmp->value_ != val)
	{
		tmp = tmp->next_;
	}

	return tmp;
}  

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_index(size_t i){
  // linear search
	auto tmp = head_;
	while (tmp && tmp->index_ != i)
	{
		tmp = tmp->next_;
	}

	return tmp;
}  

template<typename K, typename V>
void TriMap<K,V>::print_list(ostream &out){
  // this is a class member function, has access
  // to private data. Called by operator<<
	auto tmp = head_;
	while (tmp)
	{
		out << tmp->key_ << ":" << tmp->value_ << ":" << tmp->index_;
		tmp = tmp->next_;
		if (tmp)
		{
			out << ", ";
		}
	}
};


#endif
  