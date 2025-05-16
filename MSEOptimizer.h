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
#ifndef MSEOptimizer
#define MSEOptimizer


namespace NeuralNetzzz
{
    class MSEOptimizer
    {
        public:
            MSEOptimizer(NeuralNetwork *neuralNet, DataSet *trainingSet, int randomGenPrecision);
            NeuralNetwork train(int epoch, int batchSize);
            void shuffleTrainingSet();
            DelCostAndBiasOrganiTensor compPartialOfWeightAndBiasOfCostFunction(int idealActivations)
            ~MSEOptimizer();
        private:
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(0,1000000);
            int randomGenPrecision;
            NeuralNetwork *neuralNet;
            DataSet *trainingSetl
            DelCostAndBiasOrganiTensor *delWeightAndBiasOrganiTensor;

    };
}
