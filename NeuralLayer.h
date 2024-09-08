#ifndef NeuralLayer
#define NeuralLayer


namespace NeuralNetzzz
{
    template<typename ActType>
    class NeuralLayer
    {
        public:
            NeuralLayer(int numInputs, int numPerceptrons, ActType *activationFunction, float learningRate, float hyperParam, float rationalizer);
            float activations();
            Perceptron perceptronAtIndex(int index);
            int numPerceptrons();
            void loadInput(float *inputs);
            void adjustWeightsAndBiases(DelWeightAndBiasLayerObj *delWeightAndBiasLayer);
            std::vector<NeuralNetzzz::Perceptron> neuralLayer();
            ~NeuralLayer();
        private:
            std::vector<NeuralNetzzz::Perceptron> neuralLayer;
            ActType activationFunction
            int numPerceptrons;
            float rationalizer;
            float rationalNum;
    };
}