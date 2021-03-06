/*
 * Copyright (c) 2013, Robert Rueger <rueger@itp.uni-frankfurt.de>
 *
 * This file is part of hVMC.
 *
 * hVMC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * hVMC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hVMC.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "obs_sscorr.hpp"

using namespace std;

Eigen::VectorXd ObservableSpinSpinCorrelation::get_current(
  const ModelManager& model, ObservableCache& cache ) const
{
  if ( !cache.s ) {
    cache.s = model.s();
  }
  return cache.s.get().cast<double>();
}


void ObservableSpinSpinCorrelation::save_to_results(
  const Eigen::MatrixXd& corrresult, MCCResults& results ) const
{
  results.sscorr = corrresult;
}
