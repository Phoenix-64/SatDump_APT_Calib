#pragma once

#include <vector>
#include "thinplatespline.h"

namespace geodetic
{
    namespace projection
    {
        // Ground Control Point
        struct GCP
        {
            double x;
            double y;
            double lon;
            double lat;
        };

        class TPSTransform
        {
        private:
            VizGeorefSpline2D *spline_forward;
            VizGeorefSpline2D *spline_reverse;
            bool fwd_solved;
            bool rev_solved;

            bool has_been_init = false;
            double xy[2] = {0.0, 0.0};

        public:
            int init(std::vector<GCP> gcps);
            TPSTransform();
            TPSTransform(std::vector<GCP> gcps);
            ~TPSTransform();

            inline void forward(double lon, double lat, double &x, double &y)
            {
                spline_forward->get_point(lon, lat, xy);
                x = xy[0];
                y = xy[1];
            }

            inline void inverse(double x, double y, double &lon, double &lat)
            {
                spline_reverse->get_point(x, y, xy);
                lon = xy[0];
                lat = xy[1];
            }

            inline VizGeorefSpline2D &getRawForward() { return *spline_forward; }
        };
    };
};