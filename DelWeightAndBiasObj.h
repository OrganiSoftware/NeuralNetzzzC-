/*
Copyright 2025 Antonio Bruce Webb

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
#ifndef DelWeightAndBiasObj
#define DelWeightAndBiasObj

namespace NeuralNetzzz
{
    class DelWeightAndBiasObj
    {   
        public:
            DelWeightAndBiasObj(Perceptron* perceptron);
            void addDelWeigthAndBiasCalc(std::vector<float> delWeights, float delBias);
            void averageDelWeightAndBias();
            std::vector<float> delWeights();
            void clear();
            float delBias();
            ~DelWeightAndBiasObj();
        private:
            float delBias;
            int numWeightCalcs
            std::vector<float> delWeights;
            bool averaged;
    };
}
