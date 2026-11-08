#!/bin/bash

cookie="eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6OTg5Miwic2VlZCI6NjksImJhZGdlcyI6IixudWxsLCIsInR5cGUiOiIwIiwiaWF0IjoxNzk0MTY0NzUxLCJleHAiOjE3OTQ3Njk1NTF9.SlArct-3uNlYDhTUhH-pk5IlnPinsmZA-Ya09Oe25rQ"
evcodes_url="https://api.everybody.codes/user/me"

$(curl -b "everybody-codes=$cookie" "$evcodes_url" | echo $_)
