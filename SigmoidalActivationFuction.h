#ifndef SigmoidalActivationFunction
#define SigmoidalActivationFunction

namespace NeuralNetzzz
{
    class SigmoidalActivationFunction
    {
        public:
            SigmoidalActivationFunction();
            float calculate(float x);
            float compDerivative(float weightedSum, float delCost);
            ~SigmoidalActivationFunction();
    };
}