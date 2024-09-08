#ifndef DelWeightAndBiasLayerObj
#define DelWeightAndBiasLayerObj


namespace NeuralNetzzz
{
    class DelWeightAndBiasLayerObj
    {
        public:
            DelWeightAndBiasLayerObj(NeuralLayer neuralLayer);
            void averageDelWeightsAndBias();
            void addDelWeigthAndBiasCalc(int perceptronIndex, float *delWieghts, float delBias);
            NeuralNetzzz::DelWeightAndBiasObj delWeightAndBiasObjAtIndex(int perceptronIndex);
            std::vector<float> delWeights();
            std::vector<float> delBiases();
            void clear();
            ~DelWeightAndBiasLayerObj();
        private:
            std::vector<NeuralNetzzz::DelWeightAndBiasObj> delWeightAndBiasLayer;

    };
}