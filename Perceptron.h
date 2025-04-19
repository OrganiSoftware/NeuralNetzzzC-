"""
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
"""
#ifndef Perceptron
#define Perceptron

namespace NeuralNetzzz
{
    template<typename ActType>
    class Perceptron
    {
        public:
            Perceptron(ActType *activationFunction, int numInputs, float learningRate, float hyperParam, float rationalNum, int randomGenPrecision);
            float activate();
            float inputAtIndex(int inputIndex);
            float weightAtIndex(int weightIndex);
            void adjustWeights(float *delWeights);
            float calcWeightedSum();
            int numInputs();
            float bias();
            void adjustBias(float del_bias);
            void loadInputs(float *inputs);
            void loadWeightsAndBias(float *weights, float bias);
            float compPartialForMSECost(int weightIndex, bool derivingBias, float delCost);
            float calcDelCNotDelActivation(int weightIndex, float delCost);
            ~Perceptron();
        private:
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(0,1000000);
            ActType activationFunction;
            int randomGenPrecision;
            int numInputs;
            float hyperParam;
            float *weights;
            float *inputs;
            float bias = distribution(generator)/1000000;
            float storedWieghteSum;
            float rationalNum;
            bool weightsLoaded;
    };
}
