/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FrameAllocator.h
 * Author: evan
 *
 * Created on January 28, 2019, 5:22 PM
 */

#ifndef FRAMEALLOCATOR_H
#define FRAMEALLOCATOR_H

#include <vector>
#include <cstdint>
#include <string>

class FrameAllocator {
public:
    FrameAllocator(unsigned long page_count);
    
    FrameAllocator(const FrameAllocator & orig) = delete;
    FrameAllocator(FrameAllocator && orig) = delete;
    FrameAllocator operator=(const FrameAllocator & orig) = delete;
    FrameAllocator operator=(FrameAllocator && orig) = delete;
    
    virtual ~FrameAllocator();
    
    bool allocate(uint32_t count, std::vector<uint32_t> &page_frames);
    bool release(uint32_t count, std::vector<uint32_t> &page_frames);

    uint32_t get_avaliable() const;
    std::string get_avaliable_list_string() const;
    
    const unsigned long PAGE_FRAME_SIZE = 0x4000;
    
private:
    /*
     Inside of the memory array the following variables are stored:
     * PAGE_FRAMES_TOTAL (OFFSET 0, SIZE 32 BITS / 4 BYTES)
     * PAGE_FRAMES_AVALIABLE (OFFSET 4 BYTES, SIZE 4 BYTES)
     * AVALIABLE_LIST_HEAD (OFFSET 8 BYTES, SIZE 4 BYTES)
     */
    
    const unsigned long PAGE_FRAMES_TOTAL_OFFSET = 0x0;
    const unsigned long PAGE_FRAMES_AVALIABLE_OFFSET = 0x4;
    const unsigned long AVALIABLE_LIST_HEAD_OFFSET = 0x8;
    
    
    std::vector<uint8_t> memory;
    
    void store_in_memory8(uint8_t value, uint32_t address);
    void store_in_memory32(uint32_t value, uint32_t address);
    void load_from_memory8(uint8_t &value, uint32_t address) const;
    void load_from_memory32(uint32_t &value, uint32_t address) const;
    
    void set_frames_avaliable(uint32_t value);
    void set_frame_pointer(uint32_t value, uint32_t address);
    void get_head(uint32_t &value);
    
    void print_memory(uint32_t start_address, uint32_t end_address) const;

};

#endif /* FRAMEALLOCATOR_H */

