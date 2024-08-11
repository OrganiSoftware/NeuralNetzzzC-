namespace NeuralNetzzz
{   
    template<typename Type>
    class DynamicArray
    {
        public:
            DynamicArray(int size);
            void append(Type x);
            bool removeAtIndex(int index);
            Type valueAtIndex(int index);
            bool removeValue(type value);
            bool replaceAtIndex(int index);
            type copy();
            ~DynamicArray();
        
        private:
            Type *array;


    };
}