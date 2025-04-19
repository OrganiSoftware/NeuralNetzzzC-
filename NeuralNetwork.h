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
#ifndef NeuralNetwork
#define NeuralNetwork


namespace NeuralNetzzz
{   
    template<typename ActType, typename OutType>
    class NeuralNetwork
    {
        public:
            NeuralNetwork(OutType *outputTranslationTable, int sizeOfInputLayer, Type *activationFunction, float learningRate, float hyperParam, float rationalNum);
            void addInputLayer(int numPerceptrons);
            void addHiddenLayer(int numLayers, int sizeOfLayers);
            void addOutputLayer();
            int predictOutput(float *inputs);
            void loadInputs(float *inputs);
            NeuralLayer layerAtIndex(int index);
            int numNeuralLayers();
            int idealActivationForPrediction(OutType *expectedOutput, inOutTypet *rejectedOutputs);
            void saveWeightsBiases(string path);
            void loadWeightsBiases(string path);
            void adjustWeightsAndBiases(DelCostAndBiasOrganiTensor *delWeightAndBiasNetwork);
            ~NeuralNetwork();
        private:
            bool isRejected(OutType output, *rejectedOutputs);
            NeuralLayer *neuralNet;
            int sizeOfOutputLayer;
            float hyperParam;
            OutType *outputTranslationTable;
            int sizeOfInputLayer;
            float learningRate;
            bool constructed;
            float rationalNum;
            float rationalizer;
    };
}
