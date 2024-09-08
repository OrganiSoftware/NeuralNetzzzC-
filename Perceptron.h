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