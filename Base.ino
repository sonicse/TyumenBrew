State::State(boolean state /*= false*/)
: state_(state)
{}

boolean State::GetState() const
{
  return state_;
}

void State::SetState(boolean state)
{
  if (state != state_)
  {
    state_ = state;
  
    OnStateChanged();
  }
}

void State::On()
{
  SetState(true);
}

void State::Off()
{
  SetState(false);
}

void State::Toggle()
{
  SetState(!state_);
}

