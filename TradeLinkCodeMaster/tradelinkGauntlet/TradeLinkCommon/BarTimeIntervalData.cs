using System;
using System.Collections.Generic;
using System.Text;
using TradeLink.API;

namespace TradeLink.Common
{
    public class TimeIntervalData : IntervalData
    {
        public event SymBarIntervalDelegate NewBar;
        public List<decimal> open() { return opens; }
        public List<decimal> close() { return closes; }
        public List<decimal> high() { return highs; }
        public List<decimal> low() { return lows; }
        public List<long> vol() { return vols; }
        public List<int> date() { return dates; }
        public List<int> time() { return times; }
        public List<int> tick() { return ticks; }
        public bool isRecentNew() { return _isRecentNew; }
        public int Count() { return _Count; }
        public int Last() { return _Count - 1; }

        public TimeIntervalData(int unitsPerInterval)
        {
            intervallength = unitsPerInterval;
        }
        public void Reset()
        {
            opens.Clear();
            closes.Clear();
            highs.Clear();
            lows.Clear();
            dates.Clear();
            times.Clear();
            vols.Clear();
            _Count = 0;
        }
        void newbar(long id)
        {
            _Count++;
            opens.Add(0);
            closes.Add(0);
            highs.Add(0);
            lows.Add(decimal.MaxValue);
            vols.Add(0);
            times.Add(0);
            dates.Add(0);
            ids.Add(id);
        }
        public void addbar(Bar mybar)
        {
            _Count++;
            closes.Add(mybar.Close);
            opens.Add(mybar.Open);
            dates.Add(mybar.Bardate);
            highs.Add(mybar.High);
            lows.Add(mybar.Low);
            vols.Add(mybar.Volume);
            times.Add(mybar.Bartime);
            ids.Add(getbarid(mybar.Bartime, mybar.Bardate, intervallength));
        }
        long curr_barid = -1;
        int intervallength = 60;
        internal List<decimal> opens = new List<decimal>();
        internal List<decimal> closes = new List<decimal>();
        internal List<decimal> highs = new List<decimal>();
        internal List<decimal> lows = new List<decimal>();
        internal List<long> vols = new List<long>();
        internal List<int> dates = new List<int>();
        internal List<int> times = new List<int>();
        internal List<int> ticks = new List<int>();
        internal List<long> ids = new List<long>();
        internal int _Count = 0;
        internal bool _isRecentNew = false;
        public Bar GetBar(int index, string symbol)
        {
            Bar b = new BarImpl();
            if (index >= _Count) return b;
            else if (index < 0)
            {
                index = _Count - 1 + index;
                if (index < 0) return b;
            }
            b = new BarImpl(opens[index], highs[index], lows[index], closes[index], vols[index], dates[index], times[index], symbol,intervallength);
            if (index == Last()) b.isNew = _isRecentNew;
            return b;
        }

        public static bool isOldTickBackfillEnabled = true;

        public Bar GetBar(string symbol) { return GetBar(Last(), symbol); }
        public void newTick(Tick k)
        {
            // ignore quotes
            if (k.trade == 0) return;
            // get the barcount
            long barid = getbarid(k.time, k.date,intervallength);
            
            int baridx;

            //(barid != curr_barid) // what if ticks arrive a bit out of sequence?
            // Live datafeeds generally have no requirement that tick timestamps are strictly ordered.
            // as Level1 aggregates data from multiple venues, if timestamp is the exchange timestamp,
            // it is quite possible the order is different from aggregator "received" timestamp
            // The datavendors as a rule don't perform "re-sorting" of ticks based on timestamp 
            // to ensure strict ordering as it is both expensive and arguably unnecessary.
            if (barid > curr_barid)  //  true new bar needs to be formed
            {
                // create a new one
                newbar(barid);
                // mark it
                _isRecentNew = true;
                // make it current
                curr_barid = barid;
                // set time
                times[times.Count - 1] = k.time;
                // set date
                dates[dates.Count - 1] = k.date;

                baridx = Last();
            }
            else if (isOldTickBackfillEnabled && (barid < curr_barid)) // out-of sequence tick, already formed bar needs updating
            {
                baridx = ids.IndexOf(barid);
                _isRecentNew = false;
            }
            else // bar formed; update tick values
            {
                baridx = Last();

                _isRecentNew = false;
            }

            // blend tick into bar
            // open
            if (baridx >= 0)
            {
                if (opens[baridx] == 0) opens[baridx] = k.trade;
                // high
                if (k.trade > highs[baridx]) highs[baridx] = k.trade;
                // low
                if (k.trade < lows[baridx]) lows[baridx] = k.trade;
                // close
                closes[baridx] = k.trade;
                // volume
                if (k.size >= 0)
                    vols[baridx] += k.size;
            }

            // notify barlist
            if (_isRecentNew)
                NewBar(k.symbol, intervallength);
        }
        public void newPoint(string symbol, decimal p, int time, int date, int size)
        {

            // get the barcount
            long barid = getbarid(time,date,intervallength);
            // if not current bar
            if (barid != curr_barid)
            {
                // create a new one
                newbar(barid);
                // mark it
                _isRecentNew = true;
                // make it current
                curr_barid = barid;
                // set time
                times[times.Count - 1] = time;
                // set date
                dates[dates.Count - 1] = date;
            }
            else _isRecentNew = false;
            // blend tick into bar
            // open
            if (opens[Last()] == 0) opens[Last()] = p;
            // high
            if (p > highs[Last()]) highs[Last()] = p;
            // low
            if (p < lows[Last()]) lows[Last()] = p;
            // close
            closes[Last()] = p;
            // volume
            if (size>=0)
                vols[Last()] += size;
            // notify barlist
            if (_isRecentNew)
                NewBar(symbol, intervallength);

        }

        static internal long getbarid(int time, int date, int intervallength)
        {
            // get time elapsed to this point
            int elap = Util.FT2FTS(time);
            // get number of this bar in the day for this interval
            long bcount = (int)((double)elap / intervallength);
            // add the date to the front of number to make it unique
            bcount += (long)date * 10000;
            return bcount;
        }

    }
}
