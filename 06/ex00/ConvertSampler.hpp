/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertSampler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:10:32 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/27 20:02:34 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERTSAMPLER_H__
# define CONVERTSAMPLER_H__

class ConvertSampler {
    private:
        char _convertedChar;
        int _convertedInt;
        float _convertedFloat;
        double _convertedDouble;
        bool _outOfRangeFlag;
        bool _invalidInputFlag;

        static const std::out_of_range OutOfRange;
        static const std::runtime_error InvalidInput;

    public:
        ConvertSampler(void);
        ~ConvertSampler(void);
        ConvertSampler(const ConvertSampler &src);
        ConvertSampler& operator= (const ConvertSampler &src);

        ConvertSampler(const char *argv);

        char getChar(void) const;
        int getInt(void) const;
        float getFloat(void) const;
        double getDouble(void) const;
        bool getRangeErrorFlag(void) const;
        bool getInputErrorFlag(void) const;

        void input(const char *argv);

        void printChar(void) const;
        void printInt(void) const;
        void printFloat(void) const;
        void printDouble(void) const;

        void printSampler(void) const;
};

#endif
