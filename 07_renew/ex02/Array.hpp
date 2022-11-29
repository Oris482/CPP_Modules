/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:55:30 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 22:16:26 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_H__
# define ARRAY_H__

# include <algorithm>
# include <stdexcept>

template <typename T>
class Array {
    private:
        T* _tArray;
        unsigned int _size;

    public:
        Array(void): _tArray(NULL), _size(0) {}

        Array(unsigned int n): _tArray(NULL), _size(n) {
            if (this->_size) this->_tArray = new T[this->_size];
        }

        Array(const Array& src): _tArray(NULL), _size(src._size) {
            if (this->_size)
            {
                this->_tArray = new T[this->_size];
                for (unsigned int i = 0; i < this->_size; i++) {
                    this->_tArray[i] = src._tArray[i];
                }
            }
        }

        ~Array(void) {
            if (this->_tArray) delete[] _tArray;
        }

        Array& operator= (const Array& src) {
            if (this != &src)
            {
                Array temp = src;
                std::swap(this->_tArray, temp._tArray);
                std::swap(this->_size, temp._size);
            }

            return *this;
        }
        
        T& operator[] (const unsigned int idx) {
            if (idx >= this->_size) throw std::out_of_range("Out of range");

            return this->_tArray[idx];
        }        

        const T& operator[] (const unsigned int idx) const {
            if (idx >= this->_size) throw std::out_of_range("Out of range");

            return this->_tArray[idx];
        }
};

#endif
