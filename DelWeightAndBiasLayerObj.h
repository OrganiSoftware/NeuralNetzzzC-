#ifndef DelWeightAndBiasLayerObj
#define DelWeightAndBiasLayerObj
#include<DelWeightAndBiasObj.h>
#include<DynamicArray.h>

namespace NeuralNetzzz
{
    class DelWeightAndBiasLayerObj
    {
        public:
            DelWeightAndBiasLayerObj(NeuralLayer *neuralLayer);
            void averageDelWeightAndBias();
            void addDelWeigthAndBiasCalc(int perceptronIndex, float *delWieghts, float delBias);
            DelWeightAndBiasObj delWeightAndBiasObjAtIndex(int perceptronIndex);
            float delWeights();
            float delBiases();
            void clear();
            ~DelWeightAndBiasLayerObj();
        private:
            DelWeightAndBiasObj *delWeightAndBiasLayer;

    };
}