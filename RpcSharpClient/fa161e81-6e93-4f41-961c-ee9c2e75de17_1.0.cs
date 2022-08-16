namespace rpc_fa161e81_6e93_4f41_961c_ee9c2e75de17_1_0
{
    
    #region Marshal Helpers
    internal class _Marshal_Helper : NtApiDotNet.Ndr.Marshal.NdrMarshalBuffer
    {
    }
    internal class _Unmarshal_Helper : NtApiDotNet.Ndr.Marshal.NdrUnmarshalBuffer
    {
        public _Unmarshal_Helper(NtApiDotNet.Win32.Rpc.RpcClientResponse r) : 
                base(r.NdrBuffer, r.Handles, r.DataRepresentation)
        {
        }
        public _Unmarshal_Helper(byte[] ba) : 
                base(ba)
        {
        }
    }
    #endregion
    #region Client Implementation
    public sealed class Client : NtApiDotNet.Win32.Rpc.RpcClientBase
    {
        public Client() : 
                base("fa161e81-6e93-4f41-961c-ee9c2e75de17", 1, 0)
        {
        }
        private _Unmarshal_Helper SendReceive(int p, _Marshal_Helper m)
        {
            return new _Unmarshal_Helper(SendReceive(p, m.DataRepresentation, m.ToArray(), m.Handles));
        }
        public void Execute(string p0, out string p1)
        {
            _Marshal_Helper m = new _Marshal_Helper();
            m.WriteReferent(p0, new System.Action<string>(m.WriteTerminatedAnsiString));
            _Unmarshal_Helper u = SendReceive(0, m);
            p1 = u.ReadReferent<string>(new System.Func<string>(u.ReadConformantVaryingAnsiString), false);
        }
        public void ExecuteWithToken(string p0, int p1, out string p2)
        {
            _Marshal_Helper m = new _Marshal_Helper();
            m.WriteReferent(p0, new System.Action<string>(m.WriteTerminatedAnsiString));
            m.WriteInt32(p1);
            _Unmarshal_Helper u = SendReceive(1, m);
            p2 = u.ReadReferent<string>(new System.Func<string>(u.ReadConformantVaryingAnsiString), false);
        }
        public void Download(string p0, out string p1)
        {
            _Marshal_Helper m = new _Marshal_Helper();
            m.WriteReferent(p0, new System.Action<string>(m.WriteTerminatedAnsiString));
            _Unmarshal_Helper u = SendReceive(2, m);
            p1 = u.ReadReferent<string>(new System.Func<string>(u.ReadConformantVaryingAnsiString), false);
        }
        public void Upload(string p0, string p1)
        {
            _Marshal_Helper m = new _Marshal_Helper();
            m.WriteReferent(p0, new System.Action<string>(m.WriteTerminatedAnsiString));
            m.WriteReferent(p1, new System.Action<string>(m.WriteTerminatedAnsiString));
            _Unmarshal_Helper u = SendReceive(3, m);
        }
        public void Shutdown()
        {
            _Marshal_Helper m = new _Marshal_Helper();
            _Unmarshal_Helper u = SendReceive(4, m);
        }
    }
    #endregion
}

