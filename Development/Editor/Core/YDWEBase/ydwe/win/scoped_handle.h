#pragma once

#include <ydwe/util/noncopyable.h>
#include <Windows.h>

namespace ydwe { namespace win {

	template <HANDLE NullHandle>
	class scoped_handle : public util::noncopyable
	{
	public:
		scoped_handle()
			: handle_(NullHandle)
		{ }

		scoped_handle(HANDLE h)
			: handle_(h)
		{ }

		~scoped_handle()
		{
			if (!this->operator bool())
			{
				::CloseHandle(handle_);
				handle_ = NullHandle;
			}
		}

		HANDLE get() const
		{
			return handle_;
		}

		operator bool() const
		{
			return NullHandle != handle_;
		}

	protected:
		HANDLE handle_;
	};
}}