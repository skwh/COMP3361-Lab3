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

class FrameAllocator {
public:
    FrameAllocator(unsigned long page_count);
    
    FrameAllocator(const FrameAllocator & orig) = delete;
    FrameAllocator(FrameAllocator && orig) = delete;
    FrameAllocator operator=(const FrameAllocator & orig) = delete;
    FrameAllocator operator=(FrameAllocator && orig) = delete;
    
    virtual ~FrameAllocator();
    
    bool allocate(uint32_t count, std::vector<uint32_t> & page_frames);
    
    const unsigned long PAGE_FRAME_SIZE = 0x4000;
    
private:
    
    unsigned long page_count;
    std::vector<uint8_t> memory;

};

#endif /* FRAMEALLOCATOR_H */

