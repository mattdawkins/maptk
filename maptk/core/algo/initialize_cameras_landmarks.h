/*ckwg +29
 * Copyright 2014 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief Header defining abstract \link maptk::algo::initialize_cameras_landmarks
 *        bundle adjustment \endlink algorithm
 */

#ifndef MAPTK_ALGO_INITIALIZE_CAMERAS_LANDMARKS_H_
#define MAPTK_ALGO_INITIALIZE_CAMERAS_LANDMARKS_H_

#include <maptk/core/algo/algorithm.h>
#include <maptk/core/track_set.h>
#include <maptk/core/camera_map.h>
#include <maptk/core/landmark_map.h>


namespace maptk
{

namespace algo
{

/// An abstract base class for initialization of cameras and landmarks
class MAPTK_CORE_EXPORT initialize_cameras_landmarks
: public algorithm_def<initialize_cameras_landmarks>
{
public:
  /// Return the name of this algorithm
  std::string type_name() const { return "initialize_cameras_landmarks"; }

  /// Initialize the camera and landmark parameters given a set of tracks
  /**
   * The algorithm creates an initial estimate of any missing cameras and
   * landmarks using the available cameras, landmarks, and tracks.
   * It may optionally revise the estimates of exisiting cameras and landmarks.
   *
   * \param [in,out] cameras the cameras to initialize
   * \param [in,out] landmarks the landmarks to initialize
   * \param [in] tracks the tracks to use as constraints
   */
  virtual void
  initialize(camera_map_sptr& cameras,
             landmark_map_sptr& landmarks,
             track_set_sptr tracks) const = 0;
};


/// type definition for shared pointer to an initialization algorithm
typedef boost::shared_ptr<initialize_cameras_landmarks>
            initialize_cameras_landmarks_sptr;


} // end namespace algo

} // end namespace maptk


#endif // MAPTK_ALGO_INITIALIZE_CAMERAS_LANDMARKS_H_
