// Copyright William Stafford Parsons

public class StormDrop {
  public ulong a;
  public ulong b;

  public uint Next() {
    a = ((a << 29) | (a >> 35)) ^ b;
    b += 1111111111111111;
    return (uint)a;
  }
}
