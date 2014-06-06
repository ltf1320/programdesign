using System;
using System.Collections.Generic;
using System.Text;
using TradeLink.API;
using TradeLink.Common;

namespace TradeLink.Common
{
    /// <summary>
    /// loads and plays back simulations in memory for faster playback
    /// </summary>
    public class HistSimMemory : HistSimIndexPlay
    {
        bool _greedy = true;
        /// <summary>
        /// whether simulation is run in memory.
        /// if disabled runs as a histsimindexplay
        /// </summary>
        public bool inMemory { get { return _greedy; } set { _greedy = value; } }
        public HistSimMemory(string folder) : this(folder, 0) { }
        public HistSimMemory(string folder,int interval)
            : base(folder,interval)
        {
        }

        public HistSimMemory(HistSimIndex hsi)
            : base(hsi,null)
        {
        }
        public HistSimMemory(HistSimIndex hsi,DebugDelegate debug)
            : base(hsi,debug)
        {
        }


        public HistSimMemory(string folder, TickFileFilter tff)
            : base(folder, tff,0, null)
        { }

        public HistSimMemory(string folder, TickFileFilter tff,DebugDelegate deb)
            : base(folder, tff,0,deb)
        {
        }

        public HistSimMemory(string[] set,string folder) : this(set, folder,0,null) { }
        public HistSimMemory(string[] set, string folder,DebugDelegate deb) : this(set, folder, 0, deb) { }
        public HistSimMemory(string[] set, string folder, int interval,DebugDelegate deb)
            : base(set,folder,interval,deb)
        {
        }

        public event VoidDelegate NullTick;
        int _ntc = 0;
        public int NullTickCount { get { return _ntc; } set { _ntc = value; } }
        protected override void gotnewtick(Tick k)
        {

            // save in memory
            if (_greedy)
            {
                TickImpl kcopy = TickImpl.Copy(k);
                _mem.Add(kcopy);
                TickImpl kcopy1 = TickImpl.Copy(k);
                _memBackup.Add(kcopy1);
            }
            // notify user
            base.gotnewtick(k);

        }
        private List<Tick> _mem;
        private List<Tick> _memBackup;
        public override void Initialize()
        {
            
            _pc = 0;

            // size tick array
            if (_greedy && (_mem == null))
            {
                _mem = new List<Tick>(_avail);
                _memBackup = new List<Tick>(_avail);
                _inited = true;
            }
            else if (!_greedy)
                base.Initialize();
            
            
        }

        int _pc = 0;
        long _lastplayto = MultiSimImpl.STARTSIM;

        public override void PlayTo(long datetime)
        {
            if (!_inited)
                Initialize();
            if (_greedy && (datetime <= _lastplayto))
            {
                debug("Playing memory containing " + _mem.Count.ToString("N0") + " ticks.");
                // should have in memory
                stopwatch();
                for (int i = _pc; i < _mem.Count; i++)
                {
                    Tick k = _mem[i];
                    k.size = _memBackup[i].size;
                    base.gotnewtick(k);
                }
                stopwatch();
            }
            else
            {
                base.PlayTo(datetime);
                _lastplayto = datetime;
            }
        }

        public override void Reset() { Reset(false); }
        public  void Reset(bool reloaddata)
        {
            base.Reset();
            _pc = 0;
            if (reloaddata)
            {
                _lastplayto = 0;
                _mem = new List<Tick>(_avail);
                _memBackup = new List<Tick>(_avail);
            }
        }
    }
}
