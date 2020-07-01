/*
 * IndexCollector.h
 *
 *  Created on: Jun 26, 2020
 *      Author: jaw
 */


#ifndef INCLUDE_PILOT_USBOARD_INDEXCOLLECTOR_H_
#define INCLUDE_PILOT_USBOARD_INDEXCOLLECTOR_H_


#include <vector>


/**
 * A class that collects objects (optionally) identified by an index.
 */
template <class T>
class IndexCollector{
public:
	IndexCollector(size_t targetSize);
	void setTargetSize(size_t targetSize);
	bool push(const T &object, size_t index);
	void push_noindex(const T &object);
	bool complete();
	std::vector<T> clear();
private:
	size_t m_targetSize;
	std::vector<T> m_objects;
};



template <class T>
IndexCollector<T>::IndexCollector(size_t targetSize):
	m_targetSize(targetSize)
{
}


template <class T>
void IndexCollector<T>::setTargetSize(size_t targetSize){
	m_targetSize = targetSize;
}

template <class T>
bool IndexCollector<T>::push(const T &object, size_t index){
	if(index == m_objects.size()){
		m_objects.push_back(object);
		return true;
	}

	m_objects.clear();
	if(index == 0) m_objects.push_back(object);
	return false;
}


template <class T>
void IndexCollector<T>::push_noindex(const T &object){
	m_objects.push_back(object);
}


template <class T>
bool IndexCollector<T>::complete(){
	return m_objects.size() >= m_targetSize;
}


template <class T>
std::vector<T> IndexCollector<T>::clear(){
	std::vector<T> result = std::move(m_objects);
	m_objects.clear();
	return result;
}



#endif



