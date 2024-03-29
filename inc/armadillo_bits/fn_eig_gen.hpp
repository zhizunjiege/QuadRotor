// Copyright 2008-2016 Conrad Sanderson (http://conradsanderson.id.au)
// Copyright 2008-2016 National ICT Australia (NICTA)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------

//! \addtogroup fn_eig_gen
//! @{

template <typename T1>
arma_warn_unused inline
    typename enable_if2<is_supported_blas_type<typename T1::pod_type>::value, Col<std::complex<typename T1::pod_type>>>::result
    eig_gen(
        const Base<typename T1::elem_type, T1> &expr)
{
  arma_extra_debug_sigprint();

  typedef typename T1::pod_type T;
  typedef typename std::complex<T> eT;

  Col<eT> eigvals;
  Mat<eT> eigvecs;

  const bool status = auxlib::eig_gen(eigvals, eigvecs, false, expr.get_ref());

  if (status == false)
  {
    eigvals.reset();
    arma_stop_runtime_error("eig_gen(): decomposition failed");
  }

  return eigvals;
}

template <typename T1>
inline
    typename enable_if2<is_supported_blas_type<typename T1::pod_type>::value, bool>::result
    eig_gen(
        Col<std::complex<typename T1::pod_type>> &eigvals,
        const Base<typename T1::elem_type, T1> &expr)
{
  arma_extra_debug_sigprint();

  typedef typename T1::pod_type T;
  typedef typename std::complex<T> eT;

  Mat<eT> eigvecs;

  const bool status = auxlib::eig_gen(eigvals, eigvecs, false, expr.get_ref());

  if (status == false)
  {
    eigvals.reset();
    arma_debug_warn("eig_gen(): decomposition failed");
  }

  return status;
}

template <typename T1>
inline
    typename enable_if2<is_supported_blas_type<typename T1::pod_type>::value, bool>::result
    eig_gen(
        Col<std::complex<typename T1::pod_type>> &eigvals,
        Mat<std::complex<typename T1::pod_type>> &eigvecs,
        const Base<typename T1::elem_type, T1> &expr)
{
  arma_extra_debug_sigprint();

  arma_debug_check((void_ptr(&eigvals) == void_ptr(&eigvecs)), "eig_gen(): parameter 'eigval' is an alias of parameter 'eigvec'");

  const bool status = auxlib::eig_gen(eigvals, eigvecs, true, expr.get_ref());

  if (status == false)
  {
    eigvals.reset();
    eigvecs.reset();
    arma_debug_warn("eig_gen(): decomposition failed");
  }

  return status;
}

//! @}
