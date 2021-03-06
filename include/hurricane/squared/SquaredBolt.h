/**
 * licensed to the apache software foundation (asf) under one
 * or more contributor license agreements.  see the notice file
 * distributed with this work for additional information
 * regarding copyright ownership.  the asf licenses this file
 * to you under the apache license, version 2.0 (the
 * "license"); you may not use this file except in compliance
 * with the license.  you may obtain a copy of the license at
 *
 * http://www.apache.org/licenses/license-2.0
 *
 * unless required by applicable law or agreed to in writing, software
 * distributed under the license is distributed on an "as is" basis,
 * without warranties or conditions of any kind, either express or implied.
 * see the license for the specific language governing permissions and
 * limitations under the license.
 */

#pragma once

#include "hurricane/base/Fields.h"
#include "hurricane/bolt/IBolt.h"

namespace hurricane {
    namespace squared {
        class Operation;
        class SquaredTuple;
        class SquaredCollector;

        class SquaredBolt : public IBolt {
        public:
            SquaredBolt(const base::Fields& inputFields,
                const base::Fields& outputFields);

            virtual void Prepare(base::OutputCollector& outputCollector) override;
            virtual void Cleanup() override;
            virtual void Execute(const base::Values& values) override;
            virtual void Execute(const SquaredTuple& tuple,
                SquaredCollector* collector) = 0;

            virtual IBolt* Clone() const override;

            virtual Fields DeclareFields() const override;

        private:
            base::Fields _inputFields;
            base::Fields _outputFields;
            SquaredCollector* _collector;
        };
    }
}