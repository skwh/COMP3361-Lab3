/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FrameAllocator.cpp
 * Author: evan
 * 
 * Created on January 28, 2019, 5:22 PM
 */

#include "FrameAllocator.h"

FrameAllocator::FrameAllocator(unsigned long page_count) {
    this->page_count = page_count;
    this->memory = std::vector<uint8_t>(page_count * FrameAllocator::PAGE_FRAME_SIZE);
}

FrameAllocator::~FrameAllocator() {
}

