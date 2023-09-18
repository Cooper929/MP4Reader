//
//  DataEntryUrnBox.hpp
//  MP4Parser
//
//  Created by dKingbin on 2018/9/20.
//  Copyright © 2018年 dKingbin. All rights reserved.
//

#ifndef DataEntryUrnBox_hpp
#define DataEntryUrnBox_hpp

#include <stdio.h>
#include <iostream>

#include "PtrBuffer.hpp"
#include "Box.hpp"
#include "FullBox.hpp"

namespace ffstl
{
	//urn 
	class DataEntryUrnBox : public FullBox
	{
	public:
		DataEntryUrnBox(std::shared_ptr<PtrBuffer> buffer) : FullBox(buffer)
		{}

		virtual void parser(size_t& size)
		{
			FullBox::parser(size);

			size_t len = size_ - 12;
			while (len > 1)
			{
				uint8_t val = 0;
				buffer_->read(val);
				name_ += char(val);
				len--;
			}
		}

	protected:
		std::string name_;
		std::string location_;
	};
}

#endif /* DataEntryUrnBox_hpp */
