/***********************************************************************************
 *  @file       serialDebug.h
 *  Project     serial_debug
 *  @brief      Arduino Due library with functions and macros to help debug code.
 *
 *
 *  @author     Otávio Augusto Rocha da Cruz
 *  @bug 		 No known bugs.
 *  License     MIT
 *
 *  @section License
 *
 * Copyright (c) 2021 SciCoBot
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**********************************************************************************/

#ifndef SERIAL_DEBUG_H
#define SERIAL_DEBUG_H

#define DEBUG getSerial().print

#define DEBUGLN getSerial().println

#define SEPARATOR() getSerial().println("-----------------------------------------------------------------")       \

#define DEBUG_PRINT_FILE(object){                       \
 object.DEBUG("File name: ");                         \
 object.DEBUGLN(__FILE__);                            \
 object.DEBUGLN();                                  \
 }

#define DEBUG_PRINT_LINE(object){                       \
  object.DEBUG("Line: ");                             \
  object.DEBUGLN(__LINE__);                           \
  object.DEBUGLN();                                 \
}

#define DEBUG_PRINT_PRETTY_FUNCTION(object){                  \
  object.DEBUG("Function: ");                         \
  object.DEBUGLN(__PRETTY_FUNCTION__);                    \
  object.DEBUGLN();                                 \
}

#define PRINTVARIABLE(variable, object){            \
 object.DEBUG(#variable);                            \
 object.DEBUG(": ");                                  \
 object.DEBUGLN(variable);                              \
 object.DEBUGLN();                              \
}

class Debug{
	
	public:
	
		void debugTime(); 
		Debug(Stream& serial):_serial(serial){}
		Stream& getSerial();                                                         
		void debugReceiveTimeout(char* messageReceive = "Waiting a message...", uint32_t timeout = 5000);
		
	private:
		Stream& _serial;
	
};

#endif //SERIAL_DEBUG_H
