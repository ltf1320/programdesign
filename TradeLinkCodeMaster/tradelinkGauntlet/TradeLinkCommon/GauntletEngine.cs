using TradeLink.API;

namespace TradeLink.Common
{
    /// <summary>
    /// lightweight backtesting class that includes binding of data and simulation components.
    /// </summary>
    public class GauntletEngine
    {
        protected TradeLink.API.Response _r;
        protected TickFileFilter _tff;
        protected HistSim _h;
        public HistSim Engine { get { return _h; } }
        public TradeLink.API.Response response { get { return _r; } }
        public Broker SimBroker = new Broker();

        public GauntletEngine(TradeLink.API.Response r, HistSim h)
        {
            _r = r;
            bindresponse(ref _r);

            _h = h;
            bindsim(ref _h);
            
            SimBroker = new Broker();
            SimBroker.GotOrderCancel += new OrderCancelDelegate(SimBroker_GotOrderCancel);
            SimBroker.GotOrder += new OrderDelegate(_r.GotOrder);
            SimBroker.GotFill += new FillDelegate(_r.GotFill);
        }

        void bindsim(ref HistSim h)
        {
            h.GotTick += new TickDelegate(_h_GotTick);
        }
        void unbindsim(ref HistSim h)
        {
            h.GotTick -= new TickDelegate(_h_GotTick);
        }

        public virtual void UnbindEvents()
        {
            unbindresponse(ref _r);
            unbindsim(ref _h);
        }


        void bindresponse(ref Response r)
        {
            r.SendOrderEvent += new OrderSourceDelegate(_r_SendOrder);
            r.SendCancelEvent += new LongSourceDelegate(_r_SendCancel);
            r.SendDebugEvent += new DebugDelegate(_r_SendDebugEvent);
            r.SendIndicatorsEvent += new ResponseStringDel(r_SendIndicatorsEvent);
            r.SendMessageEvent += new MessageDelegate(r_SendMessageEvent);
            r.SendTicketEvent += new TicketDelegate(r_SendTicketEvent);
            r.SendChartLabelEvent += new ChartLabelDelegate(r_SendChartLabelEvent);
            r.SendBasketEvent += new BasketDelegate(r_SendBasketEvent);

        }

        void r_SendBasketEvent(Basket b, int id)
        {
            
        }

        void r_SendChartLabelEvent(decimal price, int time, string label, System.Drawing.Color c)
        {
            
        }

        void r_SendTicketEvent(string space, string user, string password, string summary, string description, Priority pri, TicketStatus stat)
        {
            
        }

        void r_SendMessageEvent(MessageTypes type, long source, long dest, long msgid, string request, ref string response)
        {
            
        }

        void r_SendIndicatorsEvent(int idx, string data)
        {
            
        }

        void unbindresponse(ref Response r)
        {
            r.SendOrderEvent -= new OrderSourceDelegate(_r_SendOrder);
            r.SendCancelEvent -= new LongSourceDelegate(_r_SendCancel);
            r.SendDebugEvent -= new DebugDelegate(_r_SendDebugEvent);
            r.SendIndicatorsEvent -= new ResponseStringDel(r_SendIndicatorsEvent);
            r.SendMessageEvent -= new MessageDelegate(r_SendMessageEvent);
            r.SendTicketEvent -= new TicketDelegate(r_SendTicketEvent);
            r.SendChartLabelEvent -= new ChartLabelDelegate(r_SendChartLabelEvent);
            r.SendBasketEvent -= new BasketDelegate(r_SendBasketEvent);
        }
        
        public GauntletEngine(TradeLink.API.Response r, TickFileFilter tff)
        {
            _r = r;
            _r.SendOrderEvent += new OrderSourceDelegate(_r_SendOrder);
            _r.SendCancelEvent += new LongSourceDelegate(_r_SendCancel);
            _r.SendDebugEvent += new DebugDelegate(_r_SendDebugEvent);
            _tff = tff;
            _h = new MultiSimImpl(_tff);
            _h.GotTick += new TickDelegate(_h_GotTick);
            SimBroker.GotOrderCancel += new OrderCancelDelegate(SimBroker_GotOrderCancel);
            SimBroker.GotOrder += new OrderDelegate(_r.GotOrder);
            SimBroker.GotFill += new FillDelegate(_r.GotFill);

        }

        public event DebugDelegate SendEngineDebugEvent;
        void debug(string msg)
        {
            if (SendEngineDebugEvent != null)
                SendEngineDebugEvent(msg);
        }

        public void Go() 
        {
            SimBroker.Reset();
            if (_r!=null)
                _r.Reset();
            if (_h != null)
            {
                _h.Reset();
                _h.PlayTo(MultiSimImpl.ENDSIM);
            }
            else
                debug("No simulation defined on gauntlet engine.");
                
        }

        void SimBroker_GotOrderCancel(string sym, bool side, long id)
        {
            _r.GotOrderCancel(id);
        }

        void SimBroker_GotOrder(Order o)
        {
            _r.GotOrder(o);
        }

        void _r_SendOrder(Order o, int id)
        {
            SimBroker.SendOrderStatus(o);
        }

        void _r_SendCancel(long number, int id)
        {
            SimBroker.CancelOrder(number);
        }

        void _h_GotTick(Tick t)
        {
            SimBroker.Execute(t);
            _r.GotTick(t);
        }

        void _r_SendDebugEvent(string msg)
        {
            
        }
    }
}
