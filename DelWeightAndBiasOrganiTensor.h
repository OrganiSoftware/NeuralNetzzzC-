#ifndef DelWeightAndBiasOrganiTensor
#define DelWeightAndBiasOrganiTensor


namespace NeuralNetzzz
{
    class DelWeightAndBiasOrganiTensor
    {
        public:
            DelWeightAndBiasOrganiTensor(NeuralNetwork *neuralNet);
            void averageDelWeightAndBiases();
            void addDelWeigthAndBiasCalc(int layerIndex, int perceptronIndex, float *delWeights, float delBias);
            DelWeightAndBiasLayerObj delWeightAndBiasObjLayerAtIndex(int layerIndex);
            float delWeights();
            float delBiases();
            void clear();
            ~DelWeightAndBiasOrganiTensor();
        private:
            DelWeightAndBiasLayerObj *delWeightAndBiasNetwork;
    };
}