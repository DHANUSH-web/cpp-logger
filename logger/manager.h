#ifndef MANAGER_H
#define MANAGER_H

#include <unordered_set>

template <typename T>
class BUF_MANAGER {
protected:
    // All instance buffers would be registered here
    // for the same runtime
    static std::string TAG;
    static inline std::unordered_set<T*> BUFFERS;

public:
    BUF_MANAGER() {
        // Initialize the buffer for current runtime
        TAG = "[BUF_MANAGER]";
        BUFFERS = std::unordered_set<T*>();
    }

    ~BUF_MANAGER() {
        // Clear all the buffers before runtime exit
        // to avoid memory overflow
        BUFFERS.clear();
    }

    // Register a new buffer for the current runtime
    static bool register_buf(T* buffer) {
        // Register the new buffer to manager
        BUFFERS.insert(buffer);
        return BUFFERS.contains(buffer);
    }

    // Unregister an existing registered buffer
    static bool unregister_buf(T* buffer) {
        BUFFERS.erase(buffer);              // remove an existing buffers from the register
        return !BUFFERS.contains(buffer);   // check if the register was removed successfully
    }

    // Get all the existing buffers in the register
    static std::unordered_set<T*> get_buffs() {
        return BUFFERS;
    }

    // Get the total number of registered buffers in the register
    static int buf_size() {
        return BUFFERS.size();
    }
};

#endif //MANAGER_H
