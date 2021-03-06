/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2012, Southwest Research Institute
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *       * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *       * Neither the name of the Southwest Research Institute, nor the names
 *       of its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BRROBOT_UTILS_H_
#define BRROBOT_UTILS_H_


/*
 * Basically a copy of the 'abb_utils.h' file by J. Zoss in the 'abb_common'
 * package, but with changed namespace declarations.
 *
 * G.A. vd. Hoorn - TU Delft Robotics Institute
 */


#include <trajectory_msgs/JointTrajectory.h>
#include <vector>


namespace brrobot
{
namespace utils
{


/**
 * \brief Corrects for parallel linkage coupling between joints.
 *
 * \param[in] joints_in input joint angles
 * \param[out] joints_out output joint angles
 * \param[in] J23_factor  Linkage factor for J2-J3.
 *   J3_out = J3_in + j23_factor * J2_in
 */
void linkage_transform(const std::vector<double>& joints_in,
    std::vector<double>* joints_out, double J23_factor = 0);

/**
 * \brief Corrects for parallel linkage coupling between joints.
 *
 * \param[in] pt_in input joint trajectory point
 * \param[out] pt_out output joint trajectory point
 * \param[in] J23_factor  Linkage factor for J2-J3.
 *   J3_out = J3_in + j23_factor * J2_in
 */
void linkage_transform(const trajectory_msgs::JointTrajectoryPoint& pt_in,
    trajectory_msgs::JointTrajectoryPoint* pt_out, double J23_factor = 0);


} //fanuc
} //utils


#endif /* BRROBOT_UTILS_H_ */
