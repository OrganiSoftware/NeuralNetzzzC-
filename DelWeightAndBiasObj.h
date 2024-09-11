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