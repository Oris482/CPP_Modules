/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MasterBox.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:30:12 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/29 02:54:56 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MASTERBOX_H__
# define MASTERBOX_H__

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

class MasterBox {
    private:
        MasterBox(const MasterBox &src);
        MasterBox& operator= (const MasterBox &src);

        static bool isSeedCreated;
        static void createSeed(void);

    public:
        MasterBox(void);
        ~MasterBox(void);

        Base* generate(void) const;
        void identify(Base* p) const;
        void identify(Base& p) const;
};

#endif
