/* Copyright (c) 2018 Baidu, Inc. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. 
*/

#ifndef ANAKIN_OPERATOR_DECONV_RELU_H
#define ANAKIN_OPERATOR_DECONV_RELU_H

#include "framework/core/base.h"
#include "framework/core/data_types.h"
#include "framework/core/operator/operator.h"
#include "utils/logger/logger.h"
#include "saber/funcs/deconv_act.h"

namespace anakin {

namespace ops {

template<typename Ttype, DataType Dtype, Precision Ptype>
class DeconvReluHelper;

/// pooling op
/**
 * \brief DeconvRelu implementation class
 * public inherit Operator
 */
template<typename Ttype, DataType Dtype, Precision Ptype>
class DeconvRelu : public Operator<Ttype, Dtype, Ptype> {
public:
    DeconvRelu() {}

    /// forward impl
    virtual void operator() (OpContext<Ttype> &ctx, 
                             const std::vector<Tensor4dPtr<Ttype, Dtype> >& ins, 
                             std::vector<Tensor4dPtr<Ttype, Dtype> >& outs) {
        LOG(ERROR) << "Not Impl Yet Operator power<TargetType:"<<"unknown"<<","
                   <<type_id<typename DataTypeWarpper<Dtype>::type>().type_info()<<">";
    }

    friend class DeconvReluHelper<Ttype, Dtype, Ptype>;
};

/**
 * \brief DeconvRelu helper class to implement it
 * public inherit OperatorHelper
 * including init resource and shape size in DeconvRelu context
 */
template<typename Ttype, DataType Dtype, Precision Ptype>
class DeconvReluHelper : public OperatorHelper<Ttype, Dtype, Ptype> {
public:
    DeconvReluHelper()=default;

    ~DeconvReluHelper();

    Status InitParam() override;

    /**
    * \brief initial all the resource needed by pooling
    * \param ctx stand for DeconvRelu operation context
    * \param ins stand for input tensor vector
    * \param outs stand for output tensor vector
    * \return status
    */
    Status Init(OpContext<Ttype> &ctx,
                const std::vector<Tensor4dPtr<Ttype, Dtype> >& ins, 
                std::vector<Tensor4dPtr<Ttype, Dtype> >& outs) override;

    /**
    * \brief infer the shape of output and input.
    * \param ins stand for input tensor vector
    * \param outs stand for output tensor vector
    * \return status
    */
    Status InferShape(const std::vector<Tensor4dPtr<Ttype, Dtype> >& ins,
                      std::vector<Tensor4dPtr<Ttype, Dtype> >& outs) override;

public:
    ///< _param_deconv_relu stand for DeconvRelu parameter
    saber::ConvActiveParam<Tensor4d<Ttype, Dtype>> _param_deconv_relu;
    ///< _funcs_deconv_relu stand for DeconvRelu function 
    saber::DeconvAct<Ttype, Dtype> _funcs_deconv_relu;

private:
    ///< _dims stand for DeconvRelu size
    PTuple<int> _dims; 
};



} /* namespace ops */

} /* namespace anakin */

#endif
