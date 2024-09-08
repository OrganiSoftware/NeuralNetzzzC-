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