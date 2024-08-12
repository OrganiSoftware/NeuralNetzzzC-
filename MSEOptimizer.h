#ifndef MSEOptimizer
#define MSEOptimizer
#include<DelWeightAndBiasOrganiTensor.h>
#include<random>

namespace NeuralNetzzz
{
    class MSEOptimizer
    {
        public:
            MSEOptimizer(NeuralNetwork *neuralNet, DataSet *trainingSet, int randomGenPercision);
            NeuralNetwork train(int epoch, int batchSize);
            void shuffleTrainingSet();
            DelCostAndBiasOrganiTensor compPartialOfWeightAndBiasOfCostFunction(int idealActivations)
            ~MSEOptimizer();
        private:
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(0,1000000);
            int randomGenPercision;
            NeuralNetwork *neuralNet;
            DataSet *trainingSetl
            DelCostAndBiasOrganiTensor *delWeightAndBiasOrganiTensor;

    };
}