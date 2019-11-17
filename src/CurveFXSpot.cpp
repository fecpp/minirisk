#include "CurveFXSpot.h"
#include "Market.h"
#include "Streamer.h"

namespace minirisk {

// last 6 letter of the curve name should be in the format of "CCYUSD", i.e. "the prices of CCY in USD".
CurveFXSpot::CurveFXSpot(Market *mkt, const Date& today, const string& curve_name)
    : m_today(today)
    , m_name(curve_name)
    , m_rate(mkt->get_fx_spot(curve_name.substr(curve_name.length() - 7, 3), curve_name.substr(curve_name.length() - 3, 3)))
{
}

double CurveFXSpot::spot() const
{
	return m_rate;
}

} // namespace minirisk
