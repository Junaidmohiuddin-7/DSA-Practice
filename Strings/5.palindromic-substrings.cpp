count = 0
for center in 0..n-1:
  count += expand(center, center)     // odd
  count += expand(center, center+1)   // even

function expand(L, R):
  local_count = 0
  while L >= 0 and R < n and s[L] == s[R]:
    local_count++
    L--; R++
  return local_count
