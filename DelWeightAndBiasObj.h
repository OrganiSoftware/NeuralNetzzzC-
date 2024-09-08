#ifndef DelWeightAndBiasObj
#define DelWeightAndBiasObj

namespace NeuralNetzzz
{
    class DelWeightAndBiasObj
    {   
        public:
            DelWeightAndBiasObj(Perceptron *perceptron);
            void addDelWeigthAndBiasCalc(float *delWeights, float delBias);
            void averageDelWeightAndBias();
            float delWeights();
            void clear();
            float delBias();
            ~DelWeightAndBiasObj();
        private:
            float delBias;
            float *delWeights;
            bool averaged;
    };
}