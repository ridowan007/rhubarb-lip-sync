#pragma once
#include "centiseconds.h"

class TimeRange {
public:
	using time_type = centiseconds;

	static TimeRange zero();

	TimeRange(time_type start, time_type end);
	TimeRange(const TimeRange&) = default;
	TimeRange(TimeRange&&) = default;

	TimeRange& operator=(const TimeRange&) = default;
	TimeRange& operator=(TimeRange&&) = default;

	time_type getStart() const;
	time_type getEnd() const;
	time_type getDuration() const;
	bool empty() const;

	void resize(const TimeRange& newRange);
	void resize(time_type start, time_type end);
	void shift(time_type offset);
	void grow(time_type value);
	void shrink(time_type value);
	void trim(const TimeRange& limits);

	bool operator==(const TimeRange& rhs) const;
	bool operator!=(const TimeRange& rhs) const;
private:
	time_type start, end;
};

std::ostream& operator<<(std::ostream& stream, const TimeRange& timeRange);
