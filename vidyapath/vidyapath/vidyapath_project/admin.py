from django.contrib import admin
# from .models import Placement
from .models import Placement, Company

admin.site.register(Placement)
admin.site.register(Company)

# Register your models here.
from .models import Registration

admin.site.register(Registration)
#admin.site.register(Placement)
