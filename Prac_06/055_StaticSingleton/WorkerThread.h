#include "SharedPreferences.cpp"

class WorkerThread {
    public:
        void play();
    private:
        void readWorker();
        void writeWorker(int value);
        std::mutex mu;
        std::vector<SharedPreferences*> answers;
};